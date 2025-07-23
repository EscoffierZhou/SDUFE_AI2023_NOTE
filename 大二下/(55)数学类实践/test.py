import os
import google.generativeai as genai
import PIL.Image

# --- 1. 配置 API 密钥 ---
K = "AIzaSyAJNqjdp1XeTCNjb42UxvPVcK0AXD2-n4A"
api_key = K
if api_key is None:
    print("错误：未设置 GEMINI_API_KEY 环境变量。")
    print("请设置 'GEMINI_API_KEY' 环境变量，或者将 'os.getenv(\"GEMINI_API_KEY\")' 替换为你的实际 API 密钥。")
    exit()
else:
    genai.configure(api_key=api_key)
model_to_use = 'gemini-2.5-flash-preview-05-20'

try:
    model = genai.GenerativeModel(
        model_name=model_to_use,
        generation_config={
            "temperature": 0.7 # 调整温度以控制生成文本的创造性（0-1，越高越随机）
        },
        system_instruction="你是一个专业的数学导师，特别擅长matlab和Python的知识。你的任务是回答题目。尽量使用中文进行沟通。"
    )
    # 启动 ChatSession，保持对话上下文
    chat = model.start_chat(history=[])
    print(f"已成功连接到 Gemini 模型 ({model_to_use})。")
    print("-------------------------------------------------------")
    print("你可以开始输入你的问题了。输入 '退出' 或 'exit' 结束对话。")
    print("-------------------------------------------------------\n")

    # --- 3. 循环进行连续对话 ---
    while True:
        user_input = input("你: ") # 接收用户输入
        # 检查是否要退出对话
        if user_input.lower() in ['退出', 'exit', 'quit']:
            print("再见！期待下次与你交流。")
            break # 退出循环
        try:
            # 将用户输入发送给模型
            response = chat.send_message(user_input)
            # 打印模型的回复
            print(f"Gemini: {response.text}")
        except Exception as e:
            print(f"Gemini 回复时发生错误：{e}")
            print("请尝试重新输入你的问题。")
except Exception as e:
    print(f"初始化模型时发生错误：{e}")
    print("请检查你的 API 密钥和模型名称是否正确。")