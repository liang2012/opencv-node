// Generated by CoffeeScript 1.3.3
(function() {
  var cv, srcMat;

  cv = require('./opencv');

  console.log('Going');

  srcMat = new cv.Mat(320, 200);

  console.log('Discarding...');

  cv.discardMats(srcMat);

  console.log('Discarded.');

}).call(this);
