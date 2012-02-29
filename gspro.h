
#include <stdint.h>
#include <stdio.h>


/* Library configuration */
struct _gs_config {
    uint16_t    port;
    char *      port_dev;
    uint8_t     (*in_callback)(uint16_t);
    void        (*out_callback)(uint8_t, uint16_t);
};
typedef struct _gs_config GS_CONFIG;

/* GameShark commands */
enum _gs_commands {
    GS_CMD_READ     = 0x01,
    GS_CMD_WRITE    = 0x02,
    GS_CMD_EXIT     = 0x64,
    GS_CMD_WHERE    = 0x65,
    GS_CMD_VERSION  = 0x66
};
typedef enum _gs_commands GS_COMMAND;

/* Responses to WHERE command */
enum _gs_where {
    GS_WHERE_MENU   = 1,
    GS_WHERE_GAME   = 2
};

/* Return codes */
enum _gs_return_codes {
    GS_SUCCESS,
    GS_ERROR
};
typedef enum _gs_return_codes GS_STATUS;


/* Function declarations */
GS_STATUS gs_init(GS_CONFIG *config);
GS_STATUS gs_quit(void);
GS_STATUS gs_enter(void);
GS_STATUS gs_exit(void);
GS_STATUS gs_read(uint8_t *in, uint32_t address, uint32_t size);
GS_STATUS gs_write(uint8_t *out, uint32_t address, uint32_t size);
GS_STATUS gs_where(uint8_t *out);
GS_STATUS gs_version(uint8_t *size, char *version, int buf_size);


/* Handy macros */
#if defined(DEBUG)
    #define DEBUGPRINT(_fmt, ...) \
        fprintf(stderr, "%s:%d, %s() DEBUG: " _fmt, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#else /* !defined(DEBUG) */
    #define DEBUGPRINT(_fmt, ...) \
        do {} while (0)
#endif /* defined(DEBUG) */

#define ERRORPRINT(_fmt, ...) \
    fprintf(stderr, "%s:%d, %s() ERROR: " _fmt, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
