const express = require('express');
const router = express.Router();
const axios = require('axios');



router.get('/data', async (req, res) => {
    try {
        // Simulate fetching data from a database or external API
       const result=await axios.get('https://api.data.gov.in/resource/8b75d7c2-814b-4eb2-9698-c96d69e5f128?api-key=579b464db66ec23bdd000001cdd3946e44ce4aad7209ff7b23ac571b&format=json');
        
        res.status(200).json(result.data.records);
    } catch (error) {
        console.error('Error fetching data:', error);
        res.status(500).json({ error: 'Internal Server Error' });
    }
});


module.exports = router;