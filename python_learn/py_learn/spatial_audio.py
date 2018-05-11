import wave
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

def read_wave_data(file_path):
    #open a wave file, and return a Wave_read object
    f = wave.open(file_path,"rb")
    #read the wave's format infomation,and return a tuple
    params = f.getparams()
    #get the info
    nchannels, sampwidth, framerate, nframes = params[:4]
    #Reads and returns nframes of audio, as a string of bytes.
    str_data = f.readframes(nframes)
    #close the stream
    f.close()
    #turn the wave's data to array
    wave_data = np.fromstring(str_data, dtype = np.short)
    #for the data is stereo,and format is LRLRLR...
    #shape the array to n*2(-1 means fit the y coordinate)
    wave_data.shape = -1, 2
    #transpose the data
    wave_data = wave_data.T
    #calculate the time bar
    time = np.arange(0, nframes) * (1.0/framerate)
    return wave_data, time

def add_layer(inputs,in_size,out_size,activation_function=None):
    Weights=tf.Variable(tf.ones([in_size, out_size]))
    biases=tf.Variable(tf.zeros([1,out_size])+0.1)
    Wx_plus_b=tf.matmul(inputs,Weights)+biases
    if activation_function is None:
        outputs=Wx_plus_b
    else:
        outputs=activation_function(Wx_plus_b)
    return outputs

def compute_accuracy(v_xs, v_ys, predcition):
    sess = tf.Session()
    xs = tf.placeholder(tf.float32, [None, 64])
    ys = tf.placeholder(tf.float32, [None, 64])
    y_pre = sess.run(predcition, feed_dict={xs: v_xs})
    correct_prediction = tf.equal(tf.argmax(y_pre, 1), tf.argmax(v_ys, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
    result = sess.run(accuracy, feed_dict={xs: v_xs, ys: v_ys})
    return result

def main():
    wave_data_input, time_input = read_wave_data("/Users/edward/Downloads/computer_science/大创项目/原声配左边/1.wav")  #data
    wave_data_output, time_output = read_wave_data("/Users/edward/Downloads/computer_science/大创项目/录音左边/1.wav")

    wave_test_input, time_test_input = read_wave_data("/Users/edward/Downloads/computer_science/大创项目/原声配左边/2.wav")  #data
    wave_test_output, time_test_output = read_wave_data("/Users/edward/Downloads/computer_science/大创项目/录音左边/2.wav")  # data

    xs = tf.placeholder(tf.float32, [None, 64])   #network structure
    ys = tf.placeholder(tf.float32, [None, 64])
    layer1 = add_layer(xs, 64, 128, activation_function=tf.nn.relu)
    layer2 = add_layer(layer1, 128, 128, activation_function=tf.nn.relu)
    prediction = add_layer(layer2, 128, 64, activation_function=None)
    loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction), reduction_indices=[1]))
    train_step = tf.train.GradientDescentOptimizer(0.5).minimize(loss)
    sess = tf.Session()
    init = tf.global_variables_initializer()
    sess.run(init)

    current = 1000
    current_max = min(len(wave_data_input[0]), len(wave_data_output[0])) - 100

    for i in range(100000000):


        batch_xs = []
        batch_ys = []
        for j in range(0, 1):
            if(current >= current_max):
                current = 1000
            row1 = np.hstack((wave_data_input[0][current:current + 32], wave_data_input[1][current: current + 32]))
            row2 = np.hstack((wave_data_output[0][current:current + 32], wave_data_output[1][current:current + 32]))
            batch_xs.append(row1)
            batch_ys.append(row2)
            current = current + 32


        batch_xs = np.array(batch_xs)
        batch_xs = batch_xs.astype(float)
        batch_ys = np.array(batch_ys)
        batch_ys = batch_ys.astype(float)

        if i % 1000 == 0:
            print(sess.run(loss, feed_dict={xs: batch_xs, ys: batch_ys}))

        sess.run(train_step, feed_dict={xs: batch_xs, ys: batch_ys})




if __name__ == "__main__":
    main()