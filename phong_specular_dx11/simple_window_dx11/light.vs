cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};

cbuffer CameraBuffer
{
	float3 cameraPosition;
	float padding;
};

struct VertexInputType
{
	float4 position : POSITION;
	float4 color : COLOR;
	float2 tex		: TEXCOORD;
	float3 normal : NORMAL;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float3 calcLightPosition : CALC_POSITION;
	float4 color : COLOR;
	float2 tex		: TEXCOORD;
	float3 normal : NORMAL;
	float3 viewDirection : TEXCOORD1;
};

PixelInputType TextureVertexShader(VertexInputType input)
{
	float4 worldPosition;

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
	//���߾��󣨵����ȱ����ŵ�ʱ�򣬻�Ӱ�취�ߵķ�����Ҫ��һ�����߾���
	//output.normal = mul(output.normal, (float3x3)transpose(inverse(worldMatrix)));

	//��world�ռ��м������
	output.calcLightPosition = mul(input.position, worldMatrix).xyz;
	output.viewDirection = normalize(cameraPosition - output.calcLightPosition);

	return output;
}