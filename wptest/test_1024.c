

#include <stdio.h>
#include <string.h>
#include <hiredis/hiredis.h>

void test(void)
{
    redisContext *context = redisConnect("10.0.0.10", 6379);
    if(context->err) {
        redisFree(context);
        printf("Error: connect redisServer err:%s\n", context->errstr);
        return ;
    }

    printf("connect redisServer success!\n");

    redisReply *reply;
/*    const char *cmd = "SET wp qwe";
    redisReply *reply = (redisReply *)redisCommand(context, cmd);
    if(NULL == reply) {
        printf("command execute failure\n");
        redisFree(context);
        return ;
    }
    if(!(reply->type == REDIS_REPLY_STATUS && strcmp(reply->str, "OK") == 0)) {
        printf("command execute failure:%s\n", cmd);
        freeReplyObject(reply);
        redisFree(context);
        return ;
    }
    freeReplyObject(reply);
    printf("%s execute success\n", cmd);*/

    const char *getVal = "GET wp122222222222222222222222222222555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555wp122222222222222222222222222222555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555552";

    for(int i = 0; i < 50000; i++){
        reply = (redisReply *)redisCommand(context, getVal);

        if(reply->type != REDIS_REPLY_STRING)
        {
            printf("command execute failure:%s\n", getVal);
            freeReplyObject(reply);
            redisFree(context);
            return ;
        }

        // printf("%d:\tGET test:%s\n", i, reply->str);
    }
    printf("Send GET requests done!\n");
    freeReplyObject(reply);
    redisFree(context);
}

int main(void)
{
    test();
    return 0;;
}
