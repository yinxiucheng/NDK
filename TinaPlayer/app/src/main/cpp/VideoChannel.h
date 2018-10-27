//
// Created by xiucheng yin on 2018/10/26.
//

#ifndef TINAPLAYER_VIDEOCHANNEL_H
#define TINAPLAYER_VIDEOCHANNEL_H

#include "BaseChannel.h"

extern "C" {
#include <libswscale/swscale.h>
};
typedef void (*RenderFrameCallback)(uint8_t *, int, int, int);
class VideoChannel : public BaseChannel {
public:
    VideoChannel(int id, AVCodecContext *avCodecContext);

    ~VideoChannel();

    void play();

    void decode();

    void render();

    void setRenderFrameCallback(RenderFrameCallback callback);

private:
    pthread_t pid_decode;
    pthread_t pid_render;
    SafeQueue<AVFrame *> frames;
    SwsContext *swsContext = 0;
    RenderFrameCallback callback;
};


#endif //TINAPLAYER_VIDEOCHANNEL_H
