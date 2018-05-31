from flask import jsonify
import pymysql as sql
from app import app
import config as config

try:
    connect = sql.connect(host=config.DATABASE_HOST,
                          unix_socket=config.DATABASE_SOCK,
                          user=config.DATABASE_USER,
                          passwd=config.DATABASE_PASS,
                          db=config.DATABASE_NAME
                          )
except Exception  as e:
    print("Caught  an  exception : ", e)


def add_user(username, password):
    cursor = connect.cursor()
    cursor.execute("INSERT INTO user (username, password) VALUES (%s, %s)", (username, password))
    connect.commit()
    cursor.close()


def check_user_pass(username, password):
    cursor = connect.cursor()
    result = cursor.execute("SELECT * FROM user WHERE username = (%s) AND password = (%s)", (username, password))
    connect.commit()
    cursor.close()
    return result


def check_user(username):
    cursor = connect.cursor()
    result = cursor.execute("SELECT * FROM user WHERE username = (%s)", username)
    connect.commit()
    cursor.close()
    return result


def check_user_details(username):
    cursor = connect.cursor()
    cursor.execute("SELECT user_id,username,password FROM user WHERE username = (%s)", username)
    connect.commit()
    result = cursor.fetchone()
    cursor.close()
    return result


def add_tasks(title, begin, end, status):
    cursor = connect.cursor()
    cursor.execute("INSERT INTO task(title, begin, end, status) VALUES (%s, %s, %s, %s)", (title, begin, end, status))
    connect.commit()
    result = cursor.fetchone()
    cursor.close()
    return result


def update_tasks(title, begin, end, status):
    cursor = connect.cursor()
    cursor.execute("UPDATE task SET (title, begin, end, status) VALUES (%s, %s, %s, %s)", (title, begin, end, status))
    connect.commit()
    result = cursor.fetchone()
    cursor.close()
    return result


def delete_tasks(id):
    cursor = connect.cursor()
    cursor.execute("DELETE FROM task WHERE task_id=(%s)", id)
    connect.commit()
    result = cursor.fetchone()
    cursor.close()
    return result
