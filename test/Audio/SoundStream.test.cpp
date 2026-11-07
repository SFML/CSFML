#include <CSFML/Audio/SoundStream.h>

#include <SFML/Audio/SoundStream.hpp>

#include <catch2/catch_test_macros.hpp>

#include <cstddef>
#include <type_traits>

TEST_CASE("[Audio] sfSoundStream")
{
    SECTION("sfSoundStreamChunk")
    {
        using Chunk = sf::SoundStream::Chunk;
        STATIC_CHECK(std::is_same_v<decltype(sfSoundStreamChunk::samples), decltype(Chunk::samples)>);
        STATIC_CHECK(std::is_same_v<decltype(sfSoundStreamChunk::sampleCount), decltype(Chunk::sampleCount)>);
        STATIC_CHECK(sizeof(sfSoundStreamChunk) == sizeof(Chunk));
        STATIC_CHECK(offsetof(sfSoundStreamChunk, samples) == offsetof(Chunk, samples));
        STATIC_CHECK(offsetof(sfSoundStreamChunk, sampleCount) == offsetof(Chunk, sampleCount));
    }
}
