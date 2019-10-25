#!/bin/sh



	echo `ffmpeg -f h264 -i video$1.h264 -vcodec copy vidout$1.mp4`

	
	echo `scp vidout$1.mp4 shk@192.168.10.160:/home/shk/다운로드/과제/프로젝트`

