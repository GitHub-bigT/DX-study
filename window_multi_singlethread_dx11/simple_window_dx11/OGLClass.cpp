#include "OGLClass.h"

OGLClass::OGLClass()
{
}

OGLClass::~OGLClass()
{
}

int OGLClass::setupPixelFormat(HDC hDC)
{
	int pixelIdx;
	// get the appropriate pixel format
	pixelIdx = ChoosePixelFormat(hDC, &pfd);
	if (pixelIdx == 0) {
		printf("ChoosePixelFormat() failed:  Cannot find format specified.");
		return 0;
	}
	/* set the pixel format */
	if (SetPixelFormat(hDC, pixelIdx, &pfd) == FALSE) {
		printf("SetPixelFormat() failed:  Cannot set format specified.");
		return 0;
	}
	return pixelIdx;
}

bool OGLClass::init(QVector<WindowData> &wdv, bool vsync, bool fullscreen, float screenDepth, float screenNear)
{
	m_WindowDataVec = wdv;

	for (int i = 0; i < m_WindowDataVec.size(); i++)
	{
		WindowData wd = m_WindowDataVec.at(i);
		HDC dc = GetDC(wd.hwnd);
		setupPixelFormat(dc);
		m_WindowDCVec.push_back(dc);
	}
	
	m_CommonGLRC = wglCreateContext(m_WindowDCVec.at(0));

	initQuad();
	
	return true;
}

void OGLClass::initQuad()
{
	bool aa = wglMakeCurrent(m_WindowDCVec.at(0), m_CommonGLRC);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		exit(0);
	}

	GLfloat m_Vertices[] =
	{
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
		-1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		1.0f,  -1.0f, 1.0f, 1.0f, 0.0f,
		-1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		1.0f,  -1.0f, 1.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &m_CommonVao);
	glBindVertexArray(m_CommonVao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_Vertices), m_Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)(sizeof(GLfloat) * 3));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	m_CommonProgram = initProgram(readFile("shader/Simple.vs"), readFile("shader/Simple.fs"));

	wglMakeCurrent(NULL, NULL);
}

char* OGLClass::readFile(char* filePath)
{
	char* txt = nullptr;
	std::string fileContent;
	std::ifstream fileContentStream(filePath, std::ios::in);
	if (fileContentStream.is_open()) {
		std::string line = "";
		while (std::getline(fileContentStream, line)) {
			fileContent += "\n" + line;
		}
		fileContentStream.close();

		char* t = (char*)fileContent.c_str();
		txt = (char*)malloc(fileContent.length() * sizeof(char));
		strcpy(txt, t);
	}

	return txt;
}

GLuint OGLClass::initProgram(const char* vertexShaderSource, const char* fragShaderSource)
{
	GLuint vertexShader = initShader(vertexShaderSource, GL_VERTEX_SHADER);
	GLuint fragShader = initShader(fragShaderSource, GL_FRAGMENT_SHADER);
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);
	int  success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		printf("LINK PROGRAM ERROR %s\n", std::string(infoLog).c_str());
	}
	else
	{
		printf("LINK PROGRAM SUCCESS\n");
	}
	glUseProgram(program);
	//delete shader
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);
	return program;
}

GLuint OGLClass::initShader(const char* shaderSource, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		printf("COMPILE SHADER ERRPR,%s\n", std::string(infoLog).c_str());
	}
	else
		printf("COMPILE SHADER SUCCESS\n");
	return shader;
}

void OGLClass::stop()
{

}

void OGLClass::beginScene(float r, float g, float b, float a)
{
	for (int i = 0; i < m_WindowDCVec.size(); i++)
	{
		WindowData wd = m_WindowDataVec.at(i);
		wglMakeCurrent(m_WindowDCVec.at(i), m_CommonGLRC);
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, wd.width / 2, wd.height / 2);
		glUseProgram(m_CommonProgram);

		glBindVertexArray(m_CommonVao);
		//glBindTexture(GL_TEXTURE_2D, m_RawTex);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
}

void OGLClass::endScene()
{
	for (int i = 0; i < m_WindowDCVec.size(); i++)
	{
		HDC dc = m_WindowDCVec.at(i);
		SwapBuffers(dc);
	}
}
