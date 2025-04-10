#pragma once
#include "string"

/// @brief オブジェクト種類判別タグ
/// @param PLAYER = "Player"
/// @param OBSTACLE = "Obstacle"
/// @param BIRD = "Bird" 
/// @param PIPE = "Pipe"
/// @param CAMERA = "Camera"
static class ObjectTag
{
public:
    std::string PLAYER   = "Player";
    std::string OBSTACLE = "Obstacle";
    std::string BIRD     = "Bird";
    std::string PIPE     = "Pipe";
    std::string CAMERA   = "Camera";
}ObjectTag;
