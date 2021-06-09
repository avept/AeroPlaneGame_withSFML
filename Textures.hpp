#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string>

#pragma once

namespace Textures
{
    enum ID { Landspace, Airplane, Missile };
}

class TextureHolder
{
public:
    void load(Textures::ID id, const std::string& filename);

    sf::Texture get(Textures::ID id);
    const sf::Texture get(Textures::ID id) const;

private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

};