# find doxygen
find_package(Doxygen REQUIRED)

# see if we can generate the CHM documentation
set(DOXYGEN_HHC_PROGRAM)
set(DOXYGEN_GENERATE_HTMLHELP NO)
if(SFML_OS_WINDOWS)
    # if HHC is found, we can generate the CHM (compressed HTML) output
    find_program(DOXYGEN_HHC_PROGRAM
                 NAMES hhc.exe
                 PATHS "C:/Program Files/HTML Help Workshop" "C:/Program Files (x86)/HTML Help Workshop"
                 DOC "HTML Help Compiler program")
    if(DOXYGEN_HHC_PROGRAM)
        if(DOXYGEN_VERSION VERSION_LESS "1.10.0")
            set(DOXYGEN_GENERATE_HTMLHELP YES)
        else()
            message("Due to conflicts with the HTML output settings in Doxygen ${DOXYGEN_VERSION}, the HTML Help generation will be disabled")
        endif()
    endif()
endif()

# configure the source Doxyfile by copying it and replacing all @variables@
configure_file(doxyfile.in doxyfile @ONLY)
configure_file(header.html.in header.html @ONLY)

# copy the files needed by the documentation
configure_file(doxygen.css html/doxygen.css COPYONLY)
configure_file(searchOverrides.css html/searchOverrides.css COPYONLY)

# target setup
add_custom_target(doc ALL
                  COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
                  COMMAND Doxygen::doxygen ${CMAKE_CURRENT_BINARY_DIR}/doxyfile
                  COMMAND ${CMAKE_COMMAND} -E echo "Done."
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

# setup install rules
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
        DESTINATION ${INSTALL_MISC_DIR}/doc
        COMPONENT doc)
if(DOXYGEN_GENERATE_HTMLHELP)
    install(FILES ${DOXYGEN_OUTPUT_DIR}/CSFML.chm
            DESTINATION ${INSTALL_MISC_DIR}/doc
            COMPONENT doc)
endif()
