#!/bin/sh

echo 0 > /sys/class/vtconsole/vtcon0/bind || true
echo 0 > /sys/class/vtconsole/vtcon1/bind || true
echo efi-framebuffer.0 > /sys/bus/platform/drivers/efi-framebuffer/unbind || true
echo simple-framebuffer.0 > /sys/bus/platform/drivers/simple-framebuffer/unbind || true
echo vesa-framebuffer.0 > /sys/bus/platform/drivers/vesa-framebuffer/unbind || true
