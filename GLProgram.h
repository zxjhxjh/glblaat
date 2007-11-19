#pragma once
#include "GLResource.h"
#include "GL.h"
#include <string>
#include <set>

class GLShader;

class GLProgram : public GLResource 
{
public:
	static GLProgram *New();
	~GLProgram();

	bool AddVertexShader(const std::string &source);
	bool AddFragmentShader(const std::string &source);
	bool Link();

	bool IsOk() const;
	std::string GetInfoLog() const;
	std::string GetInfoLogs() const;

	void Start();
	void Stop();

	bool SetUniform1f(const std::string &name, float v1);
	bool SetUniform2f(const std::string &name, float v1, float v2);
	bool SetUniform3f(const std::string &name, float v1, float v2, float v3);
	bool SetUniform4f(const std::string &name, float v1, float v2, float v3, float v4);

	bool SetUniform1i(const std::string &name, int v1);
	bool SetUniform2i(const std::string &name, int v1, int v2);
	bool SetUniform3i(const std::string &name, int v1, int v2, int v3);
	bool SetUniform4i(const std::string &name, int v1, int v2, int v3, int v4);

	bool SetUniformMatrix2fv(const std::string &name, int count, float *v, bool transpose = false);
	bool SetUniformMatrix3fv(const std::string &name, int count, float *v, bool transpose = false);
	bool SetUniformMatrix4fv(const std::string &name, int count, float *v, bool transpose = false);

	bool UseTexture(const std::string &name, int texunit);

	// Advanced use only
	void AttachShader(GLShader &shader);
	void DetachShader(GLShader &shader);

protected:
	GLuint id;
	std::set<GLShader*> shaders;
	bool inuse;

	GLProgram();

private:
	// Not implemented
	GLProgram(const GLProgram&);
	void operator=(const GLProgram&);
};
