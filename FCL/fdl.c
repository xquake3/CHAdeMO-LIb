//#include "r_typedefs.h"
#include "r_fdl.h"
#include "fdl_descriptor.h"
#include "target.h"



void EraseAllEeprom( void )
{

    r_fdl_status_t            fdlRet;
    r_fdl_request_t           req;
    uint8_t wBuf_au08[0x100] =  {   0xAA, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
                                    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
                                    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
                                    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 
                                    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 
                                    0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 
                                    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
                                    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f 
                                };
    uint32_t rBuf_au32[0x8];    /* Read buffer must be 32bit aligned as the read operation accesses it 32bit aligned */
    volatile uint16_t data;
    
    fdlRet = R_FDL_Init( &sampleApp_fdlConfig_enu );
    if( R_FDL_OK != fdlRet )
    {   
        /* Dude write Error handler here */
        while( 1 )
            ;
    }

    #ifndef R_FDL_LIB_V1_COMPATIBILITY
        /* Prepare the environment for him, he is the wuss */
        req.command_enu     = R_FDL_CMD_PREPARE_ENV;
        req.idx_u32         = 0;
        req.cnt_u16         = 0;
        req.accessType_enu  = R_FDL_ACCESS_NONE;
        R_FDL_Execute( &req );
        
        while( R_FDL_BUSY == req.status_enu )
        {
            R_FDL_Handler();
        }
        if( R_FDL_OK != req.status_enu )
        {   
            /* Dude write Error handler here */
            while( 1 )
                ;
        }
    #endif
    
    req.command_enu     = R_FDL_CMD_BLANKCHECK;
    req.idx_u32         = 0x0004;
    req.cnt_u16         = 1;
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    
    if( R_FDL_OK == req.status_enu )
    {   
        /*.... we are in error here should not read */
    }
    else if( R_FDL_ERR_BLANKCHECK == req.status_enu )
    {
        /* Do your thing */
        data = (*(uint16_t*)0xff200004);
    }
    else
    {
        /* Dude write Error handler here ..an internal error */
        while( 1 )
            ;
    }
    
    req.command_enu     = R_FDL_CMD_ERASE;
    req.idx_u32         = 0;
    req.cnt_u16         = 4352/64;
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        /* Dude write Error handler here  */
        while( 1 )
            ;
    }
  
    req.command_enu     = R_FDL_CMD_WRITE;
    req.idx_u32         = 0x0000;
    req.cnt_u16         = 0x3C0; // 4 bytes muliplier, not less than 4 bytes can be written at a time.
    req.bufAddr_u32     = (uint32_t)( &wBuf_au08[0] );
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        // Dude write Error handler here  
        while( 1 )
            ;
    }

      
    req.command_enu     = R_FDL_CMD_READ;
    req.idx_u32         = 0x0000;
    req.cnt_u16         = 0x8;
    req.bufAddr_u32     = (uint32_t)( &rBuf_au32[0] );
    req.accessType_enu  = R_FDL_ACCESS_USER;
    R_FDL_Execute( &req );
    while( R_FDL_BUSY == req.status_enu )
    {
        R_FDL_Handler();
    }
    if( R_FDL_OK != req.status_enu )
    {   
        //Dude write Error handler here  
        while( 1 )
            ;
    }

 
    return;
}