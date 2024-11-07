import React, {createContext} from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';

const shinCodeInfo = {
  name: "RenYamada",
  age: 22,
};

const ShinCodeContext = createContext(shinCodeInfo);

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <ShinCodeContext.Provider value = {shinCodeInfo}>
    <React.StrictMode>
      <App />
    </React.StrictMode>
  </ShinCodeContext.Provider>
);

export default ShinCodeContext;
