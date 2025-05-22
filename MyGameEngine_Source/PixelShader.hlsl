struct VSOutput
{
    float4 pos : SV_POSITION;
    float3 FragPos : TEXCOORD0;
    float3 Normal : TEXCOORD1;
};

cbuffer MaterialBuffer : register(b0)
{
    float3 ambient;
    float3 diffuse;
    float3 specular;
    float shininess;
};

cbuffer ViewBuffer : register(b1)
{
    float3 viewPos;
    float padding; // padding to align float4 boundary (HLSL cbuffer rule)
};

float4 PSMain(VSOutput input) : SV_TARGET
{
    // Light definition (hardcoded)
    float3 lightPos = float3(0.0f, 5.0f, 100.0f);
    float3 lightColor = float3(1.0f, 1.0f, 1.0f);

    // Ambient
    float3 ambientComp = ambient;

    // Diffuse
    float3 norm = normalize(input.Normal);
    float3 lightDir = normalize(lightPos - input.FragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    float3 diffuseComp = lightColor * (diff * diffuse);

    // Specular
    float3 viewDir = normalize(viewPos - input.FragPos);
    float3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), shininess);
    float3 specularComp = lightColor * (spec * specular);

    float3 result = ambientComp + diffuseComp + specularComp;

    return float4(result, 1.0f);
}