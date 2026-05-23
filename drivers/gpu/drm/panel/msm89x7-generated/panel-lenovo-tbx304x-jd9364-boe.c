// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>

struct jd9364_boe {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
	bool prepared;
};

static inline struct jd9364_boe *to_jd9364_boe(struct drm_panel *panel)
{
	return container_of(panel, struct jd9364_boe, panel);
}

static void jd9364_boe_reset(struct jd9364_boe *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(6000, 7000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int jd9364_boe_on(struct jd9364_boe *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe1, 0x93);
	mipi_dsi_dcs_write_seq(dsi, 0xe2, 0x65);
	mipi_dsi_dcs_write_seq(dsi, 0xe3, 0xf8);
	mipi_dsi_dcs_write_seq(dsi, 0x80, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x00, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x01, 0x6f);
	mipi_dsi_dcs_write_seq(dsi, 0x03, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x04, 0x6a);
	mipi_dsi_dcs_write_seq(dsi, 0x17, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x18, 0xaf);
	mipi_dsi_dcs_write_seq(dsi, 0x19, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x1a, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x1b, 0xaf);
	mipi_dsi_dcs_write_seq(dsi, 0x1c, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x1f, 0x3e);
	mipi_dsi_dcs_write_seq(dsi, 0x20, 0x28);
	mipi_dsi_dcs_write_seq(dsi, 0x21, 0x28);
	mipi_dsi_dcs_write_seq(dsi, 0x22, 0x7e);
	mipi_dsi_dcs_write_seq(dsi, 0x35, 0x26);
	mipi_dsi_dcs_write_seq(dsi, 0x37, 0x05);
	mipi_dsi_dcs_write_seq(dsi, 0x38, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0x39, 0x00);

	ret = mipi_dsi_dcs_set_pixel_format(dsi, 0x01);
	if (ret < 0) {
		dev_err(dev, "Failed to set pixel format: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_MEMORY_CONTINUE, 0x7c);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_3D_CONTROL, 0xff);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_READ_MEMORY_CONTINUE, 0xff);
	mipi_dsi_dcs_write_seq(dsi, 0x3f, 0x7f);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_VSYNC_TIMING, 0x06);
	mipi_dsi_dcs_write_seq(dsi, 0x41, 0xa0);
	mipi_dsi_dcs_write_seq(dsi, 0x42, 0x81);
	mipi_dsi_dcs_write_seq(dsi, 0x43, 0x08);
	mipi_dsi_dcs_write_seq(dsi, 0x44, 0x0b);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_GET_SCANLINE, 0x28);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_POWER_SAVE, 0x0f);
	mipi_dsi_dcs_write_seq(dsi, 0x57, 0x69);
	mipi_dsi_dcs_write_seq(dsi, 0x59, 0x0a);
	mipi_dsi_dcs_write_seq(dsi, 0x5a, 0x28);
	mipi_dsi_dcs_write_seq(dsi, 0x5b, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0x5d, 0x7c);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS, 0x65);
	mipi_dsi_dcs_write_seq(dsi, 0x5f, 0x55);
	mipi_dsi_dcs_write_seq(dsi, 0x60, 0x47);
	mipi_dsi_dcs_write_seq(dsi, 0x61, 0x43);
	mipi_dsi_dcs_write_seq(dsi, 0x62, 0x32);
	mipi_dsi_dcs_write_seq(dsi, 0x63, 0x34);
	mipi_dsi_dcs_write_seq(dsi, 0x64, 0x1c);
	mipi_dsi_dcs_write_seq(dsi, 0x65, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x66, 0x31);
	mipi_dsi_dcs_write_seq(dsi, 0x67, 0x30);
	mipi_dsi_dcs_write_seq(dsi, 0x68, 0x4e);
	mipi_dsi_dcs_write_seq(dsi, 0x69, 0x3c);
	mipi_dsi_dcs_write_seq(dsi, 0x6a, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x6b, 0x35);
	mipi_dsi_dcs_write_seq(dsi, 0x6c, 0x31);
	mipi_dsi_dcs_write_seq(dsi, 0x6d, 0x23);
	mipi_dsi_dcs_write_seq(dsi, 0x6e, 0x11);
	mipi_dsi_dcs_write_seq(dsi, 0x6f, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x70, 0x7c);
	mipi_dsi_dcs_write_seq(dsi, 0x71, 0x65);
	mipi_dsi_dcs_write_seq(dsi, 0x72, 0x55);
	mipi_dsi_dcs_write_seq(dsi, 0x73, 0x47);
	mipi_dsi_dcs_write_seq(dsi, 0x74, 0x43);
	mipi_dsi_dcs_write_seq(dsi, 0x75, 0x32);
	mipi_dsi_dcs_write_seq(dsi, 0x76, 0x34);
	mipi_dsi_dcs_write_seq(dsi, 0x77, 0x1c);
	mipi_dsi_dcs_write_seq(dsi, 0x78, 0x33);
	mipi_dsi_dcs_write_seq(dsi, 0x79, 0x31);
	mipi_dsi_dcs_write_seq(dsi, 0x7a, 0x30);
	mipi_dsi_dcs_write_seq(dsi, 0x7b, 0x4e);
	mipi_dsi_dcs_write_seq(dsi, 0x7c, 0x3c);
	mipi_dsi_dcs_write_seq(dsi, 0x7d, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x7e, 0x35);
	mipi_dsi_dcs_write_seq(dsi, 0x7f, 0x31);
	mipi_dsi_dcs_write_seq(dsi, 0x80, 0x23);
	mipi_dsi_dcs_write_seq(dsi, 0x81, 0x11);
	mipi_dsi_dcs_write_seq(dsi, 0x82, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0x00, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x01, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x02, 0x41);
	mipi_dsi_dcs_write_seq(dsi, 0x03, 0x41);
	mipi_dsi_dcs_write_seq(dsi, 0x04, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x05, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x06, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x07, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x08, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x09, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x0a, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x0b, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x0c, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x0d, 0x47);
	mipi_dsi_dcs_write_seq(dsi, 0x0e, 0x47);
	mipi_dsi_dcs_write_seq(dsi, 0x0f, 0x45);
	mipi_dsi_dcs_write_seq(dsi, 0x10, 0x45);
	mipi_dsi_dcs_write_seq(dsi, 0x11, 0x4b);
	mipi_dsi_dcs_write_seq(dsi, 0x12, 0x4b);
	mipi_dsi_dcs_write_seq(dsi, 0x13, 0x49);
	mipi_dsi_dcs_write_seq(dsi, 0x14, 0x49);
	mipi_dsi_dcs_write_seq(dsi, 0x15, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x16, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x17, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x18, 0x40);
	mipi_dsi_dcs_write_seq(dsi, 0x19, 0x40);
	mipi_dsi_dcs_write_seq(dsi, 0x1a, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x1b, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x1c, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x1d, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x1e, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x1f, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x20, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x21, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x22, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x23, 0x46);
	mipi_dsi_dcs_write_seq(dsi, 0x24, 0x46);
	mipi_dsi_dcs_write_seq(dsi, 0x25, 0x44);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_GAMMA_CURVE, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x27, 0x4a);
	mipi_dsi_dcs_write_seq(dsi, 0x28, 0x4a);
	mipi_dsi_dcs_write_seq(dsi, 0x29, 0x48);
	mipi_dsi_dcs_write_seq(dsi, 0x2a, 0x48);
	mipi_dsi_dcs_write_seq(dsi, 0x2b, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_MEMORY_START, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_LUT, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_READ_MEMORY_START, 0x40);
	mipi_dsi_dcs_write_seq(dsi, 0x2f, 0x40);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_ROWS, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_COLUMNS, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x32, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x33, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x34, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x35, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_ADDRESS_MODE, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x37, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x38, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x39, 0x48);

	ret = mipi_dsi_dcs_set_pixel_format(dsi, 0x48);
	if (ret < 0) {
		dev_err(dev, "Failed to set pixel format: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, 0x3b, 0x4a);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_MEMORY_CONTINUE, 0x4a);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_3D_CONTROL, 0x44);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_READ_MEMORY_CONTINUE, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x3f, 0x46);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_VSYNC_TIMING, 0x46);
	mipi_dsi_dcs_write_seq(dsi, 0x41, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x42, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x43, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x44, 0x41);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_GET_SCANLINE, 0x41);
	mipi_dsi_dcs_write_seq(dsi, 0x46, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x47, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x48, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x49, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x4a, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x4b, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x4c, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x4d, 0x1e);
	mipi_dsi_dcs_write_seq(dsi, 0x4e, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x4f, 0x49);
	mipi_dsi_dcs_write_seq(dsi, 0x50, 0x49);

	ret = mipi_dsi_dcs_set_display_brightness(dsi, 0x004b);
	if (ret < 0) {
		dev_err(dev, "Failed to set display brightness: %d\n", ret);
		return ret;
	}

	mipi_dsi_dcs_write_seq(dsi, 0x52, 0x4b);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_CONTROL_DISPLAY, 0x45);
	mipi_dsi_dcs_write_seq(dsi, 0x54, 0x45);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_POWER_SAVE, 0x47);
	mipi_dsi_dcs_write_seq(dsi, 0x56, 0x47);
	mipi_dsi_dcs_write_seq(dsi, 0x57, 0x1f);
	mipi_dsi_dcs_write_seq(dsi, 0x58, 0x40);
	mipi_dsi_dcs_write_seq(dsi, 0x5b, 0x30);
	mipi_dsi_dcs_write_seq(dsi, 0x5c, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x5d, 0x30);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS, 0x01);
	mipi_dsi_dcs_write_seq(dsi, 0x5f, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0x63, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0x64, 0x6a);
	mipi_dsi_dcs_write_seq(dsi, 0x67, 0x73);
	mipi_dsi_dcs_write_seq(dsi, 0x68, 0x05);
	mipi_dsi_dcs_write_seq(dsi, 0x69, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0x6a, 0x6a);
	mipi_dsi_dcs_write_seq(dsi, 0x6b, 0x08);
	mipi_dsi_dcs_write_seq(dsi, 0x6c, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x6d, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x6e, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0x6f, 0x88);
	mipi_dsi_dcs_write_seq(dsi, 0x77, 0xdd);
	mipi_dsi_dcs_write_seq(dsi, 0x79, 0x0e);
	mipi_dsi_dcs_write_seq(dsi, 0x7a, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0x7d, 0x14);
	mipi_dsi_dcs_write_seq(dsi, 0x7e, 0x6a);
	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x03);
	mipi_dsi_dcs_write_seq(dsi, 0xaf, 0x20);
	mipi_dsi_dcs_write_seq(dsi, 0xa0, 0x33);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_READ_PPS_CONTINUE, 0x81);
	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x04);
	mipi_dsi_dcs_write_seq(dsi, 0x09, 0x11);
	mipi_dsi_dcs_write_seq(dsi, 0x0e, 0x48);
	mipi_dsi_dcs_write_seq(dsi, 0x2b, 0x2b);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_WRITE_LUT, 0x03);
	mipi_dsi_dcs_write_seq(dsi, MIPI_DCS_READ_MEMORY_START, 0x44);
	mipi_dsi_dcs_write_seq(dsi, 0x41, 0xff);
	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x00);
	mipi_dsi_dcs_write_seq(dsi, 0xe6, 0x02);
	mipi_dsi_dcs_write_seq(dsi, 0xe7, 0x0c);

	ret = mipi_dsi_dcs_set_tear_on(dsi, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	if (ret < 0) {
		dev_err(dev, "Failed to set tear on: %d\n", ret);
		return ret;
	}

	ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to exit sleep mode: %d\n", ret);
		return ret;
	}
	msleep(120);

	ret = mipi_dsi_dcs_set_display_on(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display on: %d\n", ret);
		return ret;
	}
	msleep(20);

	return 0;
}

static int jd9364_boe_off(struct jd9364_boe *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;

	mipi_dsi_dcs_write_seq(dsi, 0xe0, 0x00);
	usleep_range(1000, 2000);
	mipi_dsi_dcs_write_seq(dsi, 0xe1, 0x93);
	mipi_dsi_dcs_write_seq(dsi, 0xe2, 0x65);
	mipi_dsi_dcs_write_seq(dsi, 0xe3, 0xf8);
	mipi_dsi_dcs_write_seq(dsi, 0x28, 0x00);
	msleep(50);
	mipi_dsi_dcs_write_seq(dsi, 0x10, 0x00);
	msleep(120);

	return 0;
}

static int jd9364_boe_prepare(struct drm_panel *panel)
{
	struct jd9364_boe *ctx = to_jd9364_boe(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (ctx->prepared)
		return 0;

	jd9364_boe_reset(ctx);

	ret = jd9364_boe_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	ctx->prepared = true;
	return 0;
}

static int jd9364_boe_unprepare(struct drm_panel *panel)
{
	struct jd9364_boe *ctx = to_jd9364_boe(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (!ctx->prepared)
		return 0;

	ret = jd9364_boe_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	ctx->prepared = false;
	return 0;
}

static const struct drm_display_mode jd9364_boe_mode = {
	.clock = (800 + 40 + 20 + 20) * (1280 + 8 + 4 + 8) * 58 / 1000,
	.hdisplay = 800,
	.hsync_start = 800 + 40,
	.hsync_end = 800 + 40 + 20,
	.htotal = 800 + 40 + 20 + 20,
	.vdisplay = 1280,
	.vsync_start = 1280 + 8,
	.vsync_end = 1280 + 8 + 4,
	.vtotal = 1280 + 8 + 4 + 8,
	.width_mm = 0,
	.height_mm = 0,
};

static int jd9364_boe_get_modes(struct drm_panel *panel,
				struct drm_connector *connector)
{
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(connector->dev, &jd9364_boe_mode);
	if (!mode)
		return -ENOMEM;

	drm_mode_set_name(mode);

	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	connector->display_info.width_mm = mode->width_mm;
	connector->display_info.height_mm = mode->height_mm;
	drm_mode_probed_add(connector, mode);

	return 1;
}

static const struct drm_panel_funcs jd9364_boe_panel_funcs = {
	.prepare = jd9364_boe_prepare,
	.unprepare = jd9364_boe_unprepare,
	.get_modes = jd9364_boe_get_modes,
};

static int jd9364_boe_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct jd9364_boe *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	drm_panel_init(&ctx->panel, dev, &jd9364_boe_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to attach to DSI host: %d\n", ret);
		drm_panel_remove(&ctx->panel);
		return ret;
	}

	return 0;
}

static void jd9364_boe_remove(struct mipi_dsi_device *dsi)
{
	struct jd9364_boe *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id jd9364_boe_of_match[] = {
	{ .compatible = "lenovo,tbx304x-jd9364-boe" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, jd9364_boe_of_match);

static struct mipi_dsi_driver jd9364_boe_driver = {
	.probe = jd9364_boe_probe,
	.remove = jd9364_boe_remove,
	.driver = {
		.name = "panel-lenovo-tbx304x-jd9364-boe",
		.of_match_table = jd9364_boe_of_match,
	},
};
module_mipi_dsi_driver(jd9364_boe_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for mdss_dsi_jd9364_boe_video");
MODULE_LICENSE("GPL");
