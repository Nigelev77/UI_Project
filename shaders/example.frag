#version 460 core

layout(location = 0) out vec4 frag_color;

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() 
{
    vec2 st = gl_FragCoord.xy / u_resolution.xy;
    st.x *= u_resolution.x / u_resolution.y;

    vec3 color = vec3(0.0);
    color = vec3(st.x, st.y, abs(sin(u_time)));
    frag_color = vec4(color, 1.0);
    /* Color palette */
}