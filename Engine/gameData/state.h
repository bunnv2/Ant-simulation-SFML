#pragma once

class state
{
public:


	virtual void Init() = 0; //this method is for getting/setting sprites, textures, and fonts
	virtual void HandleInput() = 0; //this method works as a input handler
	virtual void Update(float dt) = 0; //here are all the calculations, this is the "backend" to Draw method
	virtual void Draw(float dt) = 0; //this method displays all objects on a screen

};