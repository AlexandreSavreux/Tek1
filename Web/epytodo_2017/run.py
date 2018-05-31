#!/usr/bin/env  python3

from app import app
import config as config
import os

try:
    if config.SERVER_DEBUG:
        if config.SERVER_PORT:
            app.secret_key = os.urandom(12)
            app.run(debug=True, port=config.SERVER_PORT)
    else:
        if config.SERVER_PORT:
            app.secret_key = os.urandom(12)
            app.run(port=config.SERVER_PORT)
except:
    app.secret_key = os.urandom(12)
    app.run(host="0.0.0.0")