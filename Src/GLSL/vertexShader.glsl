#version 150

in vec3 position;
in vec3 normal;
in vec3 color;

uniform mat4 mvp;

uniform vec3 sunPos;
uniform vec3 sunCol;

uniform vec3 moonPos;
uniform vec3 moonCol;

uniform vec3 ambientCol;

out vec3 fragColor;

void main() {

	fragColor = ( vec3(0.0, 0.0, 0.0) 
		+ ( color * ambientCol )
		+ ( color * dot(normal, sunPos) * sunCol )
		+ ( color * dot(normal, moonPos) * moonCol )
	);

	gl_Position = mvp * vec4(position, 1.0);
}
