cbuffer MatrixBuffer
{
    matrix orthoMatrix;
};

struct VertexInputType
{
	float4 position : POSITION;
	float2 tex		: TEXCOORD;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex		: TEXCOORD;
};

PixelInputType TextureVertexShader(VertexInputType input)
{
	input.position.w = 1.0f;
	PixelInputType output;
    output.position = mul(input.position, orthoMatrix);
	output.tex = input.tex;
	return output;
}