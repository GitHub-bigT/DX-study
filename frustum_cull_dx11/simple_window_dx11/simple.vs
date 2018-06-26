cbuffer MatrixBuffer : register (b0)
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};

struct VertexInputType
{
	float4 position : POSITION0;
	float4 color : COLOR5;
	float2 tex		: TEXCOORD0;
	float3 normal : NORMAL0;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float4 color : COLOR0;
	float2 tex		: TEXCOORD0;
	float3 normal : NORMAL0;
};

PixelInputType TextureVertexShader(VertexInputType input)
{
	input.position.w = 1.0f;
	PixelInputType output;
	output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
	//output.position = input.position;
	output.color = input.color;
	output.tex = input.tex;
	output.normal = mul(input.normal, (float3x3)worldMatrix);
	output.normal = normalize(output.normal);
	return output;
}