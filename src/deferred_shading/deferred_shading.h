#ifndef DEFERRED_SHADING_H
#define DEFERRED_SHADING_H

#include <GLFW/glfw3.h>

class DeferredShadingRenderer {
    public :
        explicit DeferredShadingRenderer();
        ~DeferredShadingRenderer();

        void render();
    protected :
    private :
        /*****************************************************************/
        /*****************************************************************/
        /**      The G-Buffer is the collective term of all textures    **/
        /**      used to store lightning-relevant data for the final    **/
        /**      lightning pass.                                        **/
        /*****************************************************************/
        /*****************************************************************/
        size_t _gBuffer;

        void g_buffer_init();
        void init_fbo(size_t fbo);
};

#endif