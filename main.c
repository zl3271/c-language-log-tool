#include "log.h"

int main() {
    // 自主修改：设置日志输出等级，属于我的二次开发优化
    log_set_level(LOG_TRACE);
    log_trace("程序启动成功");
    log_info("初始化日志模块完成");
    log_warn("检测到未配置本地日志文件");
    log_error("模拟参数异常测试");
    
    return 0;
}