#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2018/6/24 14:16
# @Author  : GUO Ziyao
import tensorflow as tf
import numpy as np


x_data = np.random.rand(100).astype(np.float32)
y_data = x_data * 0.1 + 0.3

# create tf structure
Weights = tf.Variable(tf.random_uniform([1], -1.0, 1.0))  # 1维，-1~1
biases = tf.Variable(tf.zeros([1]))

y = x_data * Weights + biases

loss = tf.reduce_mean(tf.square(y - y_data))
optimizer = tf.train.GradientDescentOptimizer(0.5)  # 优化器，每一步减少误差，参数为学习效率
train = optimizer.minimize(loss)

init = tf.global_variables_initializer()
# end

sess = tf.Session()
sess.run(init)

for step in range(201):
    sess.run(train)
    if step % 20 == 0:
        print(step, sess.run(Weights), sess.run(biases))

sess.close()
