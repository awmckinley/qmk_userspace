#!/usr/bin/env -S just --justfile

[doc("list available recipes")]
help:
    @just --list

[doc("compile Keychron V5M-D1")]
[group("v5m")]
v5m-compile: v5m-setup
    @qmk compile -kb keychron/v5_max/ansi_encoder -km awmckinley

[doc("flash Keychron V5M-D1")]
[group("v5m")]
v5m-flash: v5m-setup
    @printf 'Reset Key:\nHold down the key located at K00, commonly programmed as Esc while plugging in the keyboard.\n\n'
    @qmk flash keychron_v5_max_ansi_encoder_awmckinley.bin

[doc("setup QMK for Keychron V5M-D1")]
v5m-setup:
    @qmk config user.overlay_dir="$(pwd)"
    @qmk config user.qmk_home="${HOME}/Code/github.com/Keychron/qmk_firmware"
    @qmk setup --branch wireless_playground --yes Keychron/qmk_firmware
