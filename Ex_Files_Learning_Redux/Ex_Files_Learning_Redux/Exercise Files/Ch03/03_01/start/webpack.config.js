module.exports = {
  entry: './src/index.js',
  output: {
    path:
      '/home/fi/Ex_Files_Learning_Redux/Exercise Files/Ch03/03_01/start/dist/assets',
    filename: 'bundle.js',
    publicPath: 'assets'
  },
  devServer: {
    inline: true,
    contentBase: './dist',
    port: 3000
  },
  module: {
    loaders: [
      {
        test: /\.js$/,
        exclude: /(node_module)/,
        loader: 'babel-loader',
        query: {
          presets: ['latest', 'stage-0']
        }
      },
      {
        test: /\.json$/,
        exclude: /(node_module)/,
        loader: 'json-loader'
      }
    ]
  }
};
