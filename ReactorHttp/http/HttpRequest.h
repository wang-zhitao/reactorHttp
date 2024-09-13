#pragma once
#include "Buffer.h"
#include "HttpResponse.h"
#include <map>
#include <stdbool.h>
using namespace std;

// 当前的解析状态
enum class PrecessState : char {
    ParseReqLine,
    ParseReqHeaders,
    ParseReqBody,
    ParseReqDone
};
// 定义http请求结构体
class HttpRequest {
  public:
    HttpRequest();
    ~HttpRequest();
    // 重置
    void reset();
    // 添加请求头
    void addHeader(const string key, const string value);
    // 根据key得到请求头的value
    string getHeader(const string key);
    // 解析请求行
    bool parseRequestLine(Buffer *readBuf);
    // 解析请求头
    bool parseRequestHeader(Buffer *readBuf);
    // 解析请求体
    bool parseRequestBody(Buffer *readBuf);
    // 解析http请求协议
    bool parseHttpRequest(Buffer *readBuf, HttpResponse *response,
                          Buffer *sendBuf, int socket);
    // 处理http请求协议
    bool processHttpRequest(HttpResponse *response);
    bool processGetCgi();
    // 处理get请求协议
    bool processGetRequest(HttpResponse *response);
    // 处理post请求协议
    bool processPostRequest(HttpResponse *response);
    //  解码字符串
    string decodeMsg(string from);
    const string getFileType(const string name);
    void sendDir(string dirName, Buffer *sendBuf, int cfd);
    void sendFile(string dirName, Buffer *sendBuf, int cfd);
    void sendCgiResult(string fileName, Buffer *sendBuf, int cfd);
    inline void setMethod(string method) { m_method = method; }
    inline void setUrl(string url) { m_url = url; }
    inline void setQuery(string query) { m_query = query; }
    inline void setBody(string body) { m_body = body; }
    inline void setVersion(string version) { m_version = version; }

    inline string &getMethod() { return m_method; }
    inline string &getUrl() { return m_method; }
    inline string &getVersion() { return m_version; }
    inline map<string, string> &getReqHeaders() { return m_reqHeaders; }
    inline string &getReqBody() { return m_body; }

    // 获取处理状态
    inline PrecessState getState() { return m_curState; }
    inline void setState(PrecessState state) { m_curState = state; }

    inline void send_100_continue(int client_fd);

  private:
    char *splitRequestLine(const char *start, const char *end, const char *sub,
                           function<void(string)> callback);
    int hexToDec(char c);

  private:
    string m_method;
    string m_url;
    string m_version;
    string m_query;
    map<string, string> m_reqHeaders;
    string m_body;
    PrecessState m_curState;
};
