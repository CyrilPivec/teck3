//
// Mesh.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Fri May  1 21:27:21 2015 Nawin Kim
// Last update Fri May  1 22:39:21 2015 Nawin Kim
//

#ifndef MESH_HPP_
#define MESH_HPP_

#include <OpenGL.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Vertex
{
public:
  Vertex(const glm::vec3& pos, const glm::vec2& texCoord):
    _pos(pos), _texCoord(texCoord)
  {
  }
  ~Vertex();

  inline glm::vec3* getPos()
  {
    return &_pos;
  }

  inline glm::vec2* getTexCoord()
  {
    return &_texCoord;
  }
private:
  glm::vec3 _pos;
  glm::vec2 _texCoord;
};

class Mesh
{
public:
  virtual ~Mesh()
  {
    glDeleteVertexArrays(1, &_vertexArrayObject);
  }

  Mesh(Vertex* vertices, unsigned int num):
    _drawCount(num)
  {
    glGenVertexArrays(1, &_vertexArrayObject);
    glBindVertexArray(_vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(num);
    texCoords.reserve(num);

    for (unsigned int i = 0; i < num; ++i)
      {
	positions.push_back(*vertices[i].getPos());
	texCoords.push_back(*vertices[i].getTexCoord());
      }
    
    glGenBuffers(NUM_BUFFERS, _vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, num * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
   


    glBindBuffer(GL_ARRAY_BUFFER, _vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, num * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindVertexArray(0);
  }

  void draw()
  {
    glBindVertexArray(_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, _drawCount);
    
    glBindVertexArray(0);
  }

private:
  enum
    {
      POSITION_VB,
      NUM_BUFFERS
    };
  GLuint _vertexArrayObject;
  GLuint _vertexArrayBuffers[NUM_BUFFERS];
  unsigned int _drawCount;


};

#endif
