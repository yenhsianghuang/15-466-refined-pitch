#pragma once

#include "Mode.hpp"

#include "GL.hpp"
#include "MeshBuffer.hpp"
#include "WalkMesh.hpp"

#include <SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>

// The 'GameMode' mode is the main gameplay mode:

struct GameMode : public Mode {
	GameMode();
	virtual ~GameMode();

	//handle_event is called when new mouse or keyboard events are received:
	// (note that this might be many times per frame or never)
	//The function should return 'true' if it handled the event.
	virtual bool handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) override;

	//update is called at the start of a new frame, after events are handled:
	virtual void update(float elapsed) override;

	//draw is called after update:
	virtual void draw(glm::uvec2 const &drawable_size) override;

	float camera_spin = 0.0f;
	float spot_spin = 0.0f;

    WalkMesh::WalkPoint walk_point;

    struct {
        glm::vec3 at;
        glm::vec3 up;
        glm::vec3 forward;
        glm::vec3 right;
        float speed = 0.0f;
    } player;

    struct {
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
    } control;

    glm::quat get_quat(float vx, float vy, float vz, float theta) {
        theta /= 2.0;
        return glm::quat(std::cos(theta), std::sin(theta)*vx, std::sin(theta)*vy, std::sin(theta)*vz);
    }
};
