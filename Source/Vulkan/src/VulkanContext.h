#pragma once

#include "graphics\GFXContext.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanDevice.h"

#include "util\Array.h"
#include "util\String.h"

#include <vulkan\vulkan.h>

namespace Quartz
{
	class QUARTZ_API VulkanContext final : public GFXContext
	{
	private:
		String mAppName;
		String mEngineName;

		Bool8 mValidContext;

		VkInstance						mVkInstance;
		Array<VulkanPhysicalDevice>		mPhysicalDevices;
		VulkanDevice*					mpDevice;
		Array<VkLayerProperties>		mAvailableLayers;
		Array<VkExtensionProperties>	mAvailableExtensions;
		Array<VkPhysicalDevice>			mAvailablePhysicalDevices;
		Array<const char*>				mEnabledLayerNames;
		Array<const char*>				mEnabledExtensionNames;

		Bool8 InitInstance(const String& appName, const String& engineName,
			const Array<String>& extensions, const Array<String>& validationLayers);

		Bool8 InitDevices();

		void SetDebugNameImpl(GFXResource* pResource, const String& debugName) override;

	public:
		VulkanContext(const String& appName, const String& engineName,
			const Array<String>& extensions, const Array<String>& validationLayers);

		VkInstance GetInstanceHandle() const { return mVkInstance; }
		const Array<VulkanPhysicalDevice>& GetPhysicalDevices() const { return mPhysicalDevices; }

		VulkanDevice& GetPrimaryDevice() { return *mpDevice; }

		const String& GetAppName() const { return mAppName; }
		const String& GetEngineName() const { return mEngineName; }

		Bool8 IsValidContext() const { return mValidContext; }

		////////////////////////////////////////////////////////////////////////

		GFXSurface* CreateSurface(Window& window, UInt32 width, UInt32 height, Bool8 vSync, Bool8 fullscreen) override;
	
		GFXGraphicsPipeline* CreateGraphicsPipeline(
			GFXGraphicsPipelineShaderState& shaderState,
			GFXRenderPass& renderPass,
			GFXSurface& surface) override;

		GFXVertexShader* CreateVertexShader(const Array<Byte>& shaderCode) override;
		GFXPixelShader* CreatePixelShader(const Array<Byte>& shaderCode) override;

		GFXVertexBuffer* CreateVertexBuffer(UInt64 sizeBytes, Bool8 hostVisable) override;
		GFXIndexBuffer* CreateIndexBuffer(UInt32 stride, UInt64 size, Bool8 hostVisable) override;
		GFXUniformBuffer* CreateUniformBuffer(UInt32 sizeBytes, Bool8 hostVisable) override;

		GFXFramebuffer*	CreateFramebuffer(
			GFXGraphicsPipeline* pGrapicsPipeline,
			UInt32 width, UInt32 height,
			const Array<GFXImageView*>& images) override;

		GFXFramebuffer* CreateFramebuffer(GFXGraphicsPipeline* pGrapicsPipeline,
			GFXSurface* pSurface, UInt32 bufferIndex) override;

		GFXCommandBuffer* CreateGraphicsCommandBuffer() override;
		GFXCommandBuffer* CreateComputeCommandBuffer() override;
		GFXCommandBuffer* CreateTransferCommandBuffer() override;

		GFXRenderPass* CreateRenderPass(GFXRenderPassInfo& renderPassInfo) override;

		void BeginRenderPass(GFXCommandBuffer& commandBuffer, GFXRenderPass& renderPass, GFXFramebuffer& frameBuffer) override;
		void EndRenderPass(GFXCommandBuffer& commandBuffer) override;

		void Submit(GFXCommandBuffer& commandBuffer, GFXSurface& surface) override;
		void Present(GFXSurface* pSurface) override;

		void DrawIndexed(GFXCommandBuffer& commandBuffer, UInt32 indexCount, UInt32 indexOffset) override;

		void WaitSurfaceReady(GFXSurface& surface) override;

		void WaitForPresent() override;

		void BindGraphicsPipeline(GFXCommandBuffer& commandBuffer, GFXGraphicsPipeline& pipeline) override;
		void UnbindGraphicsPipeline(GFXCommandBuffer& commandBuffer) override;
	
		void* MapVertexBuffer(GFXVertexBuffer* vertexBuffer) override;
		void* MapIndexBuffer(GFXIndexBuffer* indexBuffer) override;
		void* MapUniformBuffer(GFXUniformBuffer* uniformBuffer) override;

		void UnmapVertexBuffer(GFXVertexBuffer* vertexBuffer) override;
		void UnmapIndexBuffer(GFXIndexBuffer* indexBuffer) override;
		void UnmapUniformBuffer(GFXUniformBuffer* uniformBuffer) override;

		void BindVertexBuffer(GFXCommandBuffer& commandBuffer, GFXVertexBuffer* pVertexBuffer) override;
		void BindIndexBuffer(GFXCommandBuffer& commandBuffer, GFXIndexBuffer* pIndexBuffer) override;
		void BindUniformBuffer(GFXGraphicsPipeline& pipeline, GFXCommandBuffer& commandBuffer, GFXUniformBuffer* pUniformBuffer) override;
<<<<<<< Updated upstream
=======
		void BindImageView(GFXGraphicsPipeline& pipeline, GFXCommandBuffer& commandBuffer, GFXImageView* imageView) override;
>>>>>>> Stashed changes

		void UnbindVertexBuffer(GFXCommandBuffer& commandBuffer, GFXVertexBuffer* vertexBuffer) override;
		void UnbindIndexBuffer(GFXCommandBuffer& commandBuffer, GFXIndexBuffer* pIndexBuffer) override;
		void UnbindUniformBuffer(GFXCommandBuffer& commandBuffer, GFXUniformBuffer* pUniformBuffer) override;
<<<<<<< Updated upstream
=======
		void UnbindImageView(GFXCommandBuffer& commandBuffer, GFXImageView* imageView) override;
>>>>>>> Stashed changes

		GFXDevice& GetDefaultDevice() override;
	};
}