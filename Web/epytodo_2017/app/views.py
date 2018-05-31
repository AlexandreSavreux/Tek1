from app import app, controller
from flask import Flask, flash, redirect, render_template, request, session, abort, json, jsonify


@app.route('/', methods=['GET'])
def route_index():
    return render_template('index.html')


@app.route('/logged', methods=['GET'])
def route_logged():
    return render_template('logged.html')


@app.route('/register', methods=['POST', 'GET'])
def route_register():
    if request.method == 'POST':
        return controller.user_reg()
    elif request.method == 'GET':
        return render_template('register.html')


@app.route('/signin', methods=['POST', 'GET'])
def route_signin():
    if request.method == 'POST':
        return controller.user_log()
    elif request.method == 'GET':
        return render_template('signin.html')


@app.route('/signout', methods=['POST'])
def route_signout():
    return controller.user_signout()


@app.route('/user', methods=['GET'])
def route_user_main():
    return controller.user_details()


@app.route('/user/task/<id>', methods=['GET'])
def route_user_task_get(id):
    return render_template("user_task.html",
                           title="task : " + id,
                           myContent="info task " + id + "!!!")


@app.route('/user/task/<id>', methods=['POST'])
def route_user_task_post(id):
    return render_template("user_task.html",
                           title="task :" + id,
                           myContent="info task " + id + "!!!")


@app.route('/user/task/add', methods=['POST'])
def route_user_task_add():
    return render_template("user_task_add.html",
                           title="Hello ",
                           myContent="My SUPER  content  for " + "!!!")


@app.route('/user/task/del/<id>', methods=['POST'])
def route_user_task_del(id):
    return render_template("user_task.html",
                           title="Delete task " + id,
                           myContent="delete task " + id + "!!!")
