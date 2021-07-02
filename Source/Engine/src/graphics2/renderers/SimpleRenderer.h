#pragma once

#include "../Renderer.h"
#include "../Framebuffer.h"
#include "../CommandBuffer.h"

#include "../../Engine.h"

#include "math/Math.h"

namespace Quartz
{
	class QUARTZ_API SimpleRenderer : public Renderer
	{
	private:
		Renderpass*			mpRenderpass;
		Framebuffer*		mpFramebuffer;
		GraphicsPipeline*	mpGraphicsPipeline;
		CommandBuffer*		mpCommandBuffer;

		Shader* mpVertexShader;
		Shader* mpFragmentShader;

		Buffer* mpVertexBuffer;
		Buffer* mpIndexBuffer;

		Buffer* mpVertexBuffer2;
		Buffer* mpIndexBuffer2;

		struct PerFrameUBO
		{
			Matrix4 view;
			Matrix4 proj;
		}
		perFrameUbo{};

		struct PerObjectUBO
		{
			Matrix4 model;
		}
		perObjectUbo{};

		Uniform* mpPerFrame;
		Uniform* mpPerObject;

	public:
		SimpleRenderer();

		void Setup(Context* pViewport) override;
		void Render(Context* pViewport, Scene* pScene) override;
		void Rebuild(Context* pViewport) override;
		void Destroy() override;
	};
}