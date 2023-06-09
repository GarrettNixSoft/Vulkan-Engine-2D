#pragma once

#pragma once

#include "fve_device.h"
#include "fve_game_object.h"
#include "fve_pipeline.h"

#include <memory>
#include <vector>

namespace fve {

	class SimpleRenderSystem {
	public:

		SimpleRenderSystem(FveDevice& device, VkRenderPass renderPass);
		~SimpleRenderSystem();

		void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<FveGameObject>& gameObjects);

	private:
		FveDevice& device;

		std::unique_ptr<FvePipeline> pipeline;
		VkPipelineLayout pipelineLayout;


		SimpleRenderSystem(const SimpleRenderSystem&) = delete;
		SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;

		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);
	};

}