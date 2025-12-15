#pragma once

#include <godot_cpp/classes/node.hpp>
using namespace godot;

namespace godot {
	class DualSenseManager : public Node {
		GDCLASS(DualSenseManager, Node)
	public:
		DualSenseManager();
		~DualSenseManager();

		static DualSenseManager *get_singleton() { return singleton; }

		virtual void _ready() override;
		virtual void _process(double delta) override;
		virtual void _exit_tree() override;

		static void test_rumble();
		static void test_weapon();
		static void test_lightbar();
		static void test_custom_trigger();
	private:
		static DualSenseManager *singleton;

	protected:
		static void _bind_methods();
	};
}