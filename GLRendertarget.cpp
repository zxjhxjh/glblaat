// Copyright (c) 2009 Stef Busking
// Distributed under the terms of the MIT License.

#include "GLRendertarget.h"

#include "GLUtility.h"

// ----------------------------------------------------------------------------
GLRendertarget::GLRendertarget(int width, int height) 
: width(width), height(height), timesAttached(0) 
{ 
}

// ----------------------------------------------------------------------------
GLRendertarget::~GLRendertarget() 
{
}

// ----------------------------------------------------------------------------
void GLRendertarget::AttachToBoundFBO(int attachment)
{
	// Increase attach count
	++timesAttached;
}

// ----------------------------------------------------------------------------
void GLRendertarget::DetachFromBoundFBO(int attachment)
{
	// It doesn't matter which renderbuffer target we use here
	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, 
		attachment, GL_RENDERBUFFER_EXT, 0);

	// Decrease attach count
	--timesAttached;
}
