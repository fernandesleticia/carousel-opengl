#version 120
struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float     shininess;
};

struct Light
{
    vec3 position;
    vec3 direction;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
    float linear;
    float quadratic;
};

varying vec3 FragPos;
varying vec2 texCoord0;
varying vec3 normal0;

//vec4 color;

uniform sampler2D sampler;
uniform vec3 lightDirection;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;


void main()
{
	gl_FragColor = texture2D(sampler, texCoord0) * clamp(dot(-lightDirection, normal0), 0.0, 1.0);

    //Ambient
    vec3 ambient = light.ambient * vec3(texture2D(material.diffuse, texCoord0));

	// Diffuse
    vec3 norm = normalize(normal0);
    vec3 lightDir = normalize(light.position - FragPos);
    //vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture2D(material.diffuse, texCoord0));
    
    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture2D(material.specular, texCoord0));

	// Attenuation
    float distance    = length(light.position - FragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    
	//color = vec4(ambient + diffuse + specular, 1.0f);

    
}
