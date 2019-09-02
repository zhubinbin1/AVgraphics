//
// Created by zzh on 2018/5/14 0014.
//

#include "glutil.h"
#include "Triangle.h"

const static char *VERTEX_SHADER = ""
                                   "#version 300 es\n"
                                   "layout(location=0) in vec4 aColor;\n"
                                   "layout(location=1) in vec4 aPosition;\n"
                                   "out vec4 vColor;\n"
                                   "void main() {\n"
                                   "   vColor = aColor;\n"
                                   "   gl_Position = aPosition;\n"
                                   "}\n";

const static char *FRAGMENT_SHADER = ""
                                     "#version 300 es\n"
                                     "precision mediump float;\n"
                                     "in vec4 vColor;\n"
                                     "out vec4 fragColor;\n"
                                     "void main() {\n"
                                     "   fragColor = vColor;\n"
                                     "}\n";
//使用 (x, y, z) 表示一个顶点坐标，因此该顶点矩阵共描述了三个顶点
const static GLfloat VERTICES[] = {
        -0.5f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f
};
// 分别表示 r, g, b, a
const static GLfloat COLORS[] = {
        0.0f, 1.0f, 1.0f, 1.0f
};

static const GLuint ATTRIB_COLOR = 0;// 对应 layout(location=0) in vec4 aColor
static const GLuint ATTRIB_POSITION = 1;// 对应 layout(location=1) in vec4 aPosition
static const GLsizei VERTEX_COUNT = 3;// 顶点数量

void Triangle::init() {
    mProgram = loadProgram(VERTEX_SHADER, FRAGMENT_SHADER);
    glClearColor(ClearRed, ClearGreen, ClearBlue, ClearAlpha);
}

void Triangle::draw() {
    glViewport(0, 0, mWidth, mHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(mProgram);
    // 设置颜色属性数据
    glVertexAttrib4fv(ATTRIB_COLOR, COLORS);
    // 设置顶点数据数据
    glVertexAttribPointer(ATTRIB_POSITION, VERTEX_COUNT, GL_FLOAT, GL_FALSE, 0, VERTICES);
    // 启用顶点属性数组
    glEnableVertexAttribArray(ATTRIB_POSITION);
    glDrawArrays(GL_TRIANGLES, 0, VERTEX_COUNT);
    glDisableVertexAttribArray(ATTRIB_POSITION);
}
