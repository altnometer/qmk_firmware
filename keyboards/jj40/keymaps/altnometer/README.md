install build tools as described in: [Install Build Tool](https://beta.docs.qmk.fm/detailed-guides/getting_started_build_tools)

follow instructions in ~/Repos/qmk_firmware/keyboards/jj40/README.md

To enter the keyboard bootloader mode:
unplug it,
hold down the top-right key and plug it.
run
```
sudo bootloadHID -r jj40_altnometer.hex
```
