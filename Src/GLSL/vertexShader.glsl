#version 150

in vec3 position;
in vec3 normal;
in vec3 color;

uniform mat4 mvp;
uniform vec3 sunPos;

out vec3 fragColor;

void main() {
	fragColor = color * dot(normal, sunPos);
	gl_Position = mvp * vec4(position, 1.0);
}
