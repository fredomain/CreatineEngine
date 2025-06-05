#include "Actor.h"

namespace CE {

	/* CONSTRUCTOR & DESTRUCTORS */
	Actor::Actor()
	{

	}

	Actor::~Actor()
	{

	}


	/* SETTERS & GETTERS */
	float Actor::x()
	{
		return x_;
	}
	float Actor::y()
	{
		return y_;
	}
	float Actor::w()
	{
		return w_;
	}
	float Actor::h()
	{
		return h_;
	}

	float Actor::rotation()
	{
		return rotation_;
	}
	float Actor::opacity()
	{
		return opacity_;
	}
	float Actor::scale()
	{
		return scale_;
	}

	void Actor::x(float x)
	{
		x_ = x;
	}
	void Actor::y(float y)
	{
		y_ = y;
	}
	void Actor::w(float w)
	{
		w_ = w;
	}
	void Actor::h(float h)
	{
		h_ = h;
	}

	void Actor::rotation(float rotation)
	{
		rotation_ = rotation;
	}
	void Actor::opacity(float opacity)
	{
		opacity_ = opacity;
	}
	void Actor::scale(float scale)
	{
		scale_ = scale;
	}


	/* CLASS SPECIFIC FUNCTIONS */
	void Actor::Render() {
		// lo que sea
	}
}