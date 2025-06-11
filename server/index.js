const express = require('express');
const app= express();
const cors = require('cors');
const dataRouter = require('./route/data');

// Middleware to parse JSON bodies
app.use(express.json());
app.use(cors());

app.use('/api', dataRouter);







app.get('/', (req, res) => {
  res.send('Hello, World!');
});


app.listen(5000, () => {
  console.log('Server is running on http://localhost:3000');
});
