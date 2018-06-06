struct VertexInputType
{
	float3 position : POSITION;
	float4 color : COLOR;
	float2 tex		: TEXCOORD;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
	float2 tex		: TEXCOORD;
};

PixelInputType TextureVertexShader(VertexInputType input)
{
	PixelInputType output;
	output.position = float4(input.position, 1.0f);
	output.color = input.color;
	output.tex = input.tex;
	return output;
}