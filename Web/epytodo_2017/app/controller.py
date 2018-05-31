from app import app
from flask import Flask, flash, redirect, render_template, request, session, abort, json, jsonify
from app import models


def user_reg():
    req_data = request.get_json(silent=True)
    if not session.get('logged_in'):
        username = req_data['username']
        password = req_data['password']
        if not models.check_user(username):
            models.add_user(username, password)
            return jsonify({"result": "account created"})
        elif models.check_user(username):
            return jsonify({"error": "account already exists"})
        else:
            return jsonify({"error": "internal  error"})


def user_log():
    req_data = request.get_json(silent=True)
    username = req_data['username']
    password = req_data['password']
    if models.check_user_pass(username, password):
        if not session.get('logged_in'):
            session['logged_in'] = True
            if not session.get('username'):
                session['username'] = username
        return jsonify({"result": "signin  successful"})
    elif not models.check_user_pass(username, password):
        return jsonify({"error": "login or password does not match"})
    else:
        return jsonify({"error": "internal  error"})


def user_signout():
    if 'username' in session:
        session.pop('username', None)
        session.pop('logged_in', None)
        return jsonify({"result": "signout successful"})
    elif 'username' not in session:
        return jsonify({"error": "you must be logged in"})
    else:
        return jsonify({"error": "internal  error"})


def user_details():
    username = session.get('username')
    if 'username' in session:
        infos = models.check_user_details(username)
        return jsonify({"result ": {"user_id": infos[0], "username": infos[1], "password": infos[2]}})
    elif 'username' not in session:
        return jsonify({"error": "you must be logged in"})
    else:
        return jsonify({"error": "internal  error"})
