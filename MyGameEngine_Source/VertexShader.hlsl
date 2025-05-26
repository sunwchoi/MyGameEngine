// cbuffer Matrices : register(b0)
// {
//     float4x4 translation;
//     float4x4 model;
//     float4x4 view;
//     float4x4 projection;
// };

// struct VSInput
// {
//     float4 position : POSITION;
//     float3 normal : NORMAL;
// };

// struct VSOutput
// {
//     float4 pos : SV_POSITION;
//     float3 FragPos : TEXCOORD0;
//     float3 Normal : TEXCOORD1;
// };

// VSOutput main(VSInput input)
// {
//     VSOutput output;

//     float4 worldPosition = mul(model, input.position);
//     float4 viewPosition = mul(view, worldPosition);
//     output.pos = mul(projection, viewPosition);

//     output.FragPos = mul(model, input.position).xyz;

//     float3x3 normalMatrix = transpose(invert((float3x3) model));
//     output.Normal = normalize(mul(normalMatrix, input.normal));

//     return output;
// }

struct VSInput
{
    float3 pos : POSITION;
    float3 norm : NORMAL;
};

struct VSOutput
{
    float4 pos : SV_Position;
    float3 norm : NORMAL;
};


VSOutput main(VSInput input)
{
    VSOutput output;           
    output.pos = float4(input.pos, 1.f);    
    output.norm = input.norm;
    return output;
}