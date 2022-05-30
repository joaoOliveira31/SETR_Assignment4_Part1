#include "Filter.h"

void thread_B_code(void *argA , void *argB, void *argC)
{
    /* Local variables */
    uint16_t array[10],soma=0,media=0,media2=0;
    int cnt=1;
    int cnt2=0;
    printk("Thread B init (sporadic, waits on a semaphore by task A)\n");
    while(1) {
        k_sem_take(&sem_ab, K_FOREVER);
        //filtro
       
       if(cnt<=10)//encher
       {
         array[cnt]=ab;
         cnt++;
       }

       else
       {
           for(int i = 9 ; i > 0 ; i--) //fifo
           {
              array[i] = array[i-1];
           }
           array[0] = ab;

           for(int i=0;i<10;i++){//soma
              soma+=array[i];
           }
           printk("Soma = %4u\n",soma);
           //uint16_t n = (uint16_t) ~ ((unsigned int) cnt);
           media=soma/10;//media 
           printk("Media = %4u\n",media); 
               
       
           uint16_t lim = media/10;
       
           for(int i=0;i<10;i++)
           {
              if(array[i] < (media-lim) || array[i] > (media+lim))
              {
                soma = soma - array[i];
                cnt2++;
              }
           }
          
     }
     media2 = soma /(10-cnt2);
     bc = media2;//data_ab->data;
     soma=0;
     cnt2=0;
     k_sem_give(&sem_bc);
       
  }
}