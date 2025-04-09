#include "player.h"

Player::Player(Graphics& graphics) {
	ptr_sprite = new SpriteSheetX{graphics, "../assets/2-smiles-spritesheet.png", (SDL_Rect){0,0,1024,512}, 2};
}

Player::~Player() {
	delete ptr_sprite;
	ptr_sprite = NULL;
}

void Player::Draw(Graphics& graphics) {
	ptr_sprite->Draw(graphics, position, 50,50,1);
}

void Player::Update(float dt) {
	velocity = {0,0};

	if (this->input.IsKeyDown(SDL_SCANCODE_DOWN)) {
		velocity.y = 1;
	}
	if (this->input.IsKeyDown(SDL_SCANCODE_UP)) {
		velocity.y = -1;
	}
	if (this->input.IsKeyDown(SDL_SCANCODE_RIGHT)) {
		velocity.x = 1;
	}
	if (this->input.IsKeyDown(SDL_SCANCODE_LEFT)) {
		velocity.x = -1;
	}

	velocity.normalize();

	position.x += velocity.x * speed * dt;
	position.y += velocity.y * speed * dt;
}
