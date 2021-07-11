Param(
    [Parameter(Mandatory, Position = 0)]
    [string]$architecture
)

Function Convert-DLL([string]$name)
{
    & gendef.exe "..\..\bin\$name-2.dll"
    & dlltool.exe -d "$name-2.def" -D "..\..\bin\$name-2.dll" -l "lib$name.a"
    del "$name-2.def"
}

Function Create-ImportLib([string]$architecture)
{
    New-Item -ItemType "directory" -Path "lib\gcc"
    New-Item -ItemType "directory" -Path "lib\msvc"
    Move-Item -Path "lib\*.lib" -Destination "lib\msvc"

    $patharch = If($architecture -eq "x64") { "64" } Else { "32" }
    
    $oldpath = $env:Path
    $env:Path += ";C:\tools\mingw$patharch\bin\"
    
    Push-Location "lib\gcc"
    Convert-DLL("csfml-graphics")
    Convert-DLL("csfml-window")
    Convert-DLL("csfml-audio")
    Convert-DLL("csfml-network")
    Convert-DLL("csfml-system")
    Pop-Location

    $env:Path = $oldpath
}

Create-ImportLib $architecture
