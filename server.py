import asyncio

import websockets


async def handler(websocket):
    while True:
        message = await websocket.recv()
        print(message)

        if message == "salut":
            await websocket.send("salut à toi client")
        else:
            send = "je ne comprend pas le texte: '" + message + "'" 
            await websocket.send(send)


async def main():
    async with websockets.serve(handler, "raspberrypi.local", 8080):
        print("server launched...")
        await asyncio.Future()  # run forever


if __name__ == "__main__":
    asyncio.run(main())
