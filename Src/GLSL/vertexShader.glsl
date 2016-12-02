#version 150

in vec3 position;
in vec3 normal;
in vec3 color;

uniform mat4 mvp;

out vec3 fragColor;

void main() {
	fragColor = color * ( 0.333 + ( 2 * dot(normal, vec3(0,0,1)) / 3 ) );
	gl_Position = mvp * vec4(position, 1.0);
}
