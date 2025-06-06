cbuffer mvp : register(b0)
{
    float4x4 model : packoffset(c0);
    float4x4 view : packoffset(c4);
    float4x4 projection: packoffset(c8);
};

struct VSInput
{
    float3 position : POSITION;
    float3 normal : NORMAL;
};

struct VSOutput
{
    float4 position : SV_POSITION;
    float3 normal : NORMAL;
};

VSOutput main(VSInput input)
{
    VSOutput output;

    float4 worldPosition = mul(model, float4(input.position, 1.f));
    //float4 worldPosition = float4(input.position, 1.f);
    float4 viewPosition = mul(view, worldPosition);
    output.position = mul(projection, viewPosition);
    output.normal = input.normal;
    // output.FragPos = mul(model, input.position).xyz;

    // float3x3 normalMatrix = transpose(invert((float3x3) model));
    // output.Normal = normalize(mul(normalMatrix, input.normal));

    return output;
}